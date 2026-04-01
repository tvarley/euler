var assert = require('assert');
var solution078 = require('../src/euler/solution078');

describe('Solution078', function() {
  describe('answer', function() {
    it('will answer problem 078', function() {
      assert.equal(solution078.answer(), 55374);
    });
  });
});