var assert = require('assert');
var solution076 = require('../src/euler/solution076');

describe('Solution076', function() {
  describe('answer', function() {
    it('will answer problem 076', function() {
      assert.equal(solution076.answer(), 190569291n);
    });
  });
});