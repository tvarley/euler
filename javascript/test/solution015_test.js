var assert = require('assert');
var solution015 = require('../src/euler/solution015');

describe('Solution015', function() {
  describe('answer', function() {
    it('will answer problem 015', function() {
      assert.equal(solution015.answer(), 137846528820n);
    });
  });
});