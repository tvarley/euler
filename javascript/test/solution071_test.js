var assert = require('assert');
var solution071 = require('../src/euler/solution071');

describe('Solution071', function() {
  describe('answer', function() {
    it('will answer problem 071', function() {
      assert.equal(solution071.answer(), 428570);
    });
  });
});